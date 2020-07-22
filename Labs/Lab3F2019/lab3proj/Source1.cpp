void setup() {
	// put your setup code here, to run once:

	pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
	pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
	Serial.begin(9600); // Starts the serial communication
	pinMode(10, OUTPUT); // Sets the RED LED
	pinMode(5, OUTPUT); // Sets the Red Relay
	pinMode(11, OUTPUT); // Sets the Green Relay
	pinMode(4, OUTPUT); // Sets the Green LED
	pinMode(6, INPUT); // Sets the switch

}
// Creating a struct for Position Vector
struct positionij {
	int positionxi;
	int positionyj;
};
// Creating a struct for Velocity Vector
struct velocityij {
	double velocityxi;
	double velocityyj;
};
// Creating a struct for Acceleration Vector
struct accelij {
	double accelxi;
	double accelyj;
};
struct predpos {
	int positionxi[10];
	int positionyj[10];
};
struct distances
{
	double avgdistance1, avgdistance2;

};


// defines pins numbers
const int trigPin1 = 7; // for first radar
const int echoPin1 = 8;  // for first radar
const int trigPin2 = 2; // for second radar
const int echoPin2 = 3;  // for second radar
const int dt = 10; // time in millisecond for speed of scanning
const double dist_S1andABS = 13.64;// Distance between sensor1 and absolute axis
const double dist_S2andABS = 13.64;// Distance between sensor2 and absolute axis
const double dist_S1andS2 = 24.13;// Distance between sensor1 and sensor2

// defines variables
long duration1, duration2;
double DP1, DP2;
double idistance1, idistance2, A, E, F, P0, Po, H, I, Dpk, dpk, alpha, X, Y, radar1[20], radar2[20];
const double d10 = dist_S1andABS;
const double d20 = dist_S2andABS;
const double d21 = dist_S1andS2;
int cnttime = 0;



// Defining Struct to Default for arithemetic for the first iterations
positionij positionij_1P = { 0,0 };
positionij positionij_2P = { 0,0 };
positionij positionij_3P = { 0,0 };
velocityij velocityij_1V = { 0,0 };
velocityij velocityij_2V = { 0,0 };
accelij accelij_A = { 0,0 };
predpos positionij_PD;
distances bothsensors[5];

void loop() {
	for (int k = 0, k < 5, k++)
	{
		bothsensors[k] = returndistance();
		DP1 += bothsensors[k].avgdistance1;
		DP2 += bothsensors[k].avgdistance2;
	}
	DP1 = DP1 / 5;
	DP2 = DP2 / 5;

	// Position at t=1 Vector 
	positionij positionij_1P = Mainreturnpos(DP1, DP2);
	delay(100 * dt);

	for (int k = 0, k < 5, k++)
	{
		bothsensors[k] = returndistance();
		DP1 += bothsensors[k].avgdistance1;
		DP2 += bothsensors[k].avgdistance2;
	}
	DP1 = DP1 / 5;
	DP2 = DP2 / 5;

	// Position at t=2 Vector 
	positionij positionij_2P = Mainreturnpos(DP1, DP2);
	delay(100 * dt);
	for (int k = 0, k < 5, k++)
	{
		bothsensors[k] = returndistance();
		DP1 += bothsensors[k].avgdistance1;
		DP2 += bothsensors[k].avgdistance2;
	}
	DP1 = DP1 / 5;
	DP2 = DP2 / 5;

	// Position at t=3 Vector 
	positionij positionij_3P = Mainreturnpos(DP1, DP2);

	//Velocity vector from t=1 to t=2
	velocityij velocityij_1V = Mainreturnvel(positionij_1P, positionij_2P);
	//Velocity vector from t=2 to t=3
	velocityij velocityij_2V = Mainreturnvel(positionij_2P, positionij_3P);
	//Acceleration vector from t=1 to t=3
	accelij accelij_A = Mainreturnacc(velocityij_1V, velocityij_2V);

	//Printing Desired Data
	//Serial.print("Current Position: <");
	Serial.print(positionij_1P.positionxi);
	Serial.print(",");

	Serial.print(positionij_1P.positionyj);
	//Serial.print(">\n");


	  //Serial.print("Predicted Position: ");
	CalcPrdPosition(positionij_3P, velocityij_2V, accelij_A, positionij_PD);

	for (int k = 0; k < 4; k++)
	{
		//Serial.print("at t= ");
		//Serial.print(k);
		//Serial.print("<");
		//not needed when in Data Streamer
		//Serial.print("\n");
		Serial.print(",");
		Serial.print(positionij_PD.positionxi[k]);
		Serial.print(",");
		// Serial.print("\n");
		Serial.print(positionij_PD.positionyj[k]);
		//Serial.print(">\n");
	}
	Serial.print("\n");


	loop();

}


//Calculation function for Predicted Position Vector
void CalcPrdPosition(positionij positionijt, velocityij velocityijt, accelij accelijt, predpos& positionij_PD)
{
	int t = 0;
	for (int k = 0; k < 10; k++)
	{

		positionij_PD.positionxi[k] = (positionijt.positionxi + (velocityijt.velocityxi * t) + (.5 * accelijt.accelxi * pow(t, 2)));

		positionij_PD.positionyj[k] = (positionijt.positionyj + (velocityijt.velocityyj * t) + (.5 * accelijt.accelyj * pow(t, 2)));
		t++;
		//+ Serial.print(positionij_PD.positionxi[k]);
		//+ Serial.print(",");
		//+ Serial.print(positionij_PD.positionyj[k]);
		//+ Serial.print("   ");

	}

}

//Calculation function for acceleration Vector
accelij Mainreturnacc(velocityij velocityij_1Vt, velocityij velocityij_2Vt)
{
	accelij accelij_At = { 0,0 };

	accelij_At.accelxi = (velocityij_1Vt.velocityxi - velocityij_2Vt.velocityxi) / 1;
	accelij_At.accelyj = (velocityij_1Vt.velocityyj - velocityij_2Vt.velocityyj) / 1;


	//+ Serial.print(accelij_At.accelxi);
	 //+Serial.print(",");
	 //+Serial.print(accelij_At.accelyj);
	 //+Serial.print("   ");

	return accelij_At;

}
//Calculation function for Velocity Vector
velocityij Mainreturnvel(positionij positionij_P1t, positionij positionij_P2t)
{
	velocityij velocityij_t = { 0,0 };

	velocityij_t.velocityxi = (positionij_P1t.positionxi - positionij_P2t.positionxi) / 1;
	velocityij_t.velocityyj = (positionij_P1t.positionyj - positionij_P2t.positionyj) / 1;


	return velocityij_t;
}
distances returndistance()
{
	distances temp = { 0,0 };
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin1, HIGH);
	digitalWrite(trigPin2, HIGH);
	delay(dt);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	digitalWrite(trigPin1, LOW);
	duration1 = pulseIn(echoPin1, HIGH);
	digitalWrite(echoPin1, LOW);
	digitalWrite(trigPin2, LOW);
	duration2 = pulseIn(echoPin2, HIGH);
	digitalWrite(echoPin2, LOW);
	// Calculating the distance
	idistance1 = duration1 * 0.034 / 2;
	idistance2 = duration2 * 0.034 / 2;

	/*
	// if the difference between the distance of the two sensors is greater than 18cm the data recieved from sensors is flawed.
	if(abs(idistance1-idistance2) > 18.00)
	{
	  returndistance();
	}
	*/
	// Prints the distance on the Serial Monitor
	if (idistance1 > 400.00 || idistance2 > 400.00)
	{
		idistance1 = 400.00;
		idistance2 = 400.00;

	}

	temp.avgdistance1 = idistance1;
	temp.avgdistance2 = idistance2;



	//For LED's
	if ((idistance1 < 100) || (idistance2 < 100)) {
		digitalWrite(10, HIGH);
		digitalWrite(5, HIGH);
		digitalWrite(4, LOW);
		digitalWrite(11, LOW);
	}
	else
	{
		digitalWrite(10, LOW);
		digitalWrite(5, LOW);
		digitalWrite(4, HIGH);
		digitalWrite(11, HIGH);
	}


	return temp;
}


positionij mainreturnpos(double DP1, double DP2)
{
	positionij positionij_t = { 0,0 };


	//Calculations for translating distance from each vector to position in cartesian coordinates
	A = (acos(((pow(d21, 2)) + (pow(d20, 2)) - (pow(d10, 2))) / (2 * d21 * d20))) * 57.2957795;
	E = (acos(((pow(d21, 2)) + (pow(DP2, 2)) - (pow(DP1, 2))) / (2 * d21 * DP2))) * 57.2957795;
	F = (acos((pow(DP1, 2) + pow(DP2, 2) - pow(d21, 2)) / (2 * DP1 * DP2))) * 57.2957795;
	Po = (sqrt(abs((2 * d20 * DP2 * cos(E - A)) - pow(d20, 2) - pow(DP2, 2))));
	P0 = (sqrt(abs(pow(d20, 2) + pow(DP2, 2) - (2 * d20 * DP2 * cos(E - A)))));
	H = (acos((pow(P0, 2) + pow(DP2, 2) - pow(d20, 2)) / (2 * P0 * DP2))) * 57.2957795;
	I = (acos((pow(P0, 2) + pow(d20, 2) - pow(DP2, 2)) / (2 * P0 * d20))) * 57.2957795;
	dpk = (sqrt(abs(2 * P0 * d20 * cos(I) - pow(P0, 2) - pow(d20, 2))));
	Dpk = sqrt(abs(pow(P0, 2) + pow(d20, 2) - (2 * P0 * d20 * cos(I))));
	alpha = abs(((acos((pow(DP1, 2) + pow(Dpk, 2) - pow(d21, 2)) / (2 * DP1 * Dpk))) * 57.2957795) - F);
	X = abs(P0 * sin(alpha + H));
	Y = abs(P0 * cos(alpha + H));

	//To clean data setting Threshold 
	if (!(X > 0 || X < 1000))
	{
		X = 0;
		Y = 0;
	}
	//assigning the postion values to the Postion Vector 
	positionij_t.positionxi = X;
	positionij_t.positionyj = Y;

	//returning the struct
	return positionij_t;

}

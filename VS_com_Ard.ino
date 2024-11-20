String mySt; 
	char myChar = 0; 
	int i=0; 
void setup() { 
  pinMode(2, OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(2,LOW);
	//digitalWrite(3,HIGH);
  // start serial port at 9600 bps: 
	Serial.begin(9600); 
	while (!Serial) { 
	; // wait for serial port to connect. Needed for native USB port only 
	} 
  establishContact();  //send a byte to establish contact until receiver responds
	} 
void loop() { 
	if (Serial.available() > 0) { 
	  myChar = Serial.read(); 
	  mySt +=myChar; //receive string from Computer 
	 } 
	  if ((mySt.length() >0)&(!Serial.available())) { 
      if(mySt == "KILL SERIAL"){
        digitalWrite(2,HIGH);
        Serial.end();
      }
	    Serial.print(mySt); //Print received string to Computer 
	    mySt=""; 
	 } 
	} 
	void establishContact() { 
	  while (Serial.available() <= 0) {
	    Serial.print("Arduino send: "); 
	    Serial.println(i); //Print increasing value to Computer 
	    i+=1; 
	    delay(500); 
	} 
	} 

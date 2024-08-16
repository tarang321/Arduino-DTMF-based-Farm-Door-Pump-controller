




const int m11=9;
const int m12=10;
const int m21=11;
const int m22=12;

const int D0=A5;
const int D1=A4;
const int D2=A3;
const int D3=A2;

void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}
void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}

void setup() 
{
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);

  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}

void loop() 
{

  int temp1=digitalRead(D0);
  int temp2=digitalRead(D1);
  int temp3=digitalRead(D2);
  int temp4=digitalRead(D3);
 
  if(temp1==0 && temp2==1 && temp3==0 && temp4==0) //Binary value received from DTMF Module - 0100 == 4
  forward();

  else if(temp1==0 && temp2==1 && temp3==1 && temp4==0) //0110 == 6
  backward();

  
  else if(temp1==1 && temp2==0 && temp3==1 && temp4==0) //0101 == 5
  Stop();
}

#include <Servo.h>
// KOKU ID TANIMLAMALARI
#define bos 0
#define cilek 1
#define muz 2
#define mandalina 3
#define kavun 4

// KOKU YOĞUNLUKLARI
#define az 1
#define normal 2
#define cok 3

// VERİ İNDİS TANIMLAMALARI
#define indis_koku 0
#define indis_kokuYogunluk 1
#define indis_kokuSuresi 2

// KOKU MODÜLÜNDEKİ HAZNELERE BAS/BIRAK MAKROLARI
#define birak 500
#define basAciSag
#define basAciSol
#define birakAci
#define hazne1 s1.write(basAciSag);delay(birak);s1.write(birakAci);delay(birak)
#define hazne2 s1.write(basAcıSol);delay(birak);s1.write(birakAci);delay(birak)
#define hazne3 s2.write(basAciSag);delay(birak);s2.write(birakAci);delay(birak)
#define hazne4 s2.write(basAciSol);delay(birak);s2.write(birakAci);delay(birak)
#define hazne5 s3.write(basAciSag);delay(birak);s3.write(birakAci);delay(birak)
#define hazne6 s3.write(basAciSol);delay(birak);s3.write(birakAci);delay(birak)

unsigned char koku=bos;
unsigned char kokuYogunluk=az;
unsigned char kokuSuresi=5; // 1-60 arası tamsayı sn cinsinden.

unsigned char garbage; // bufferda kalan artık veriyi temizlemek için
unsigned char veri[3]={koku,kokuYogunluk,kokuSuresi}; // gelen veriler.


Servo s1;
Servo s2;
Servo s3;
#define fan1 6
#define fan2 5

#define led1 A0
#define led2 A1
#define led3 A2
#define led4 A3
#define led5 A4
#define led6 A5

#define Time 1000
#define Time2 5000

void flash(void);

void setup() {


delay(3000);
Serial.begin(9600);
flash();
s1.attach(11);
s2.attach(10);
s3.attach(9);
pinMode(fan1,OUTPUT);
pinMode(fan2,OUTPUT);

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);

}

void loop() 
{
#if 1 // docklight üzerinden koku testi
bas:
while(uart.available()<=0);
veri[indis_koku]=(unsigned char)uart.read();
veri[indis_kokuYogunluk]=(unsigned char)uart.read();
veri[indis_kokuSuresi]=(unsigned char)uart.read();

garbage=uart.read();
delay(20);
garbage=uart.read();

// gelen veri denetimi

if(veri[indis_koku]<0 || veri[indis_koku]>4) {/*Serial.println("HATALI KOKU ID BILGISI");*/ goto bas;}

if( veri[indis_kokuYogunluk] <1 || veri[indis_kokuYogunluk] >3) {/*Serial.println("HATALI KOKU YOGUNLUK BILGISI ");*/ goto bas;}

if(veri[indis_kokuSuresi]<0 || veri[indis_kokuSuresi]>60) {/*Serial.println("HATALI KOKU SURE BILGISI");*/ goto bas;}


// Serial.print(" koku: "); Serial.print(veri[0]);
// Serial.print(" yogunluk: "); Serial.print(veri[1]);
// Serial.print( "sure: "); Serial.println(veri[2]);
 
 switch (veri[indis_koku])
 {
  case cilek:
  digitalWrite(fan2,1);delay(50); hazne6; delay(1000);digitalWrite(fan2,0);
  break;
  
  case muz:
  //analogWrite(mos2,veri[indis_kokuYogunluk]*70);delay(veri[indis_kokuSuresi]*1000); dur();
  break;

  case kavun:
  //analogWrite(mos3,veri[indis_kokuYogunluk]*70);delay(veri[indis_kokuSuresi]*1000); dur();
  break;

  case mandalina:
  //analogWrite(mos4,veri[indis_kokuYogunluk]*70);delay(veri[indis_kokuSuresi]*1000); dur();
  break;
  default:;
 }
#endif

#if 0 // donanım testleri
s1.write(0);delay(Time); s1.write(180);delay(Time);

s2.write(0);delay(Time); s2.write(180);delay(Time);

s3.write(0);delay(Time); s3.write(180);delay(Time);

analogWrite(fan1,200); delay(Time); analogWrite(fan1,0); delay(Time);

analogWrite(fan2,200); delay(Time2); analogWrite(fan2,0); delay(Time2);

delay(5000);

for(unsigned char x=0b00000001; x<0b00100000;x<<1)
{
digitalWrite(led1,0b1&x); 
digitalWrite(led2,0b10&x); 
digitalWrite(led3,0b100&x); 
digitalWrite(led4,0b1000&x); 
digitalWrite(led5,0b10000&x); 
digitalWrite(led6,0b100000&x); 
delay(600);
}


for(unsigned char x=0b00100000; x>0b00000001;x>>1)
{
digitalWrite(led1,0b1&x); 
digitalWrite(led2,0b10&x); 
digitalWrite(led3,0b100&x); 
digitalWrite(led4,0b1000&x); 
digitalWrite(led5,0b10000&x); 
digitalWrite(led6,0b100000&x); 
delay(600);
}
#endif

}// End Loop

void flash(void)
{
  for(int j=0; j<5; j++)
  {
  digitalWrite(led1,1); digitalWrite(led2,1);digitalWrite(led3,1);digitalWrite(led4,1);digitalWrite(led5,1);digitalWrite(led6,1);
  delay(500);
  digitalWrite(led1,0); digitalWrite(led2,0);digitalWrite(led3,0);digitalWrite(led4,0);digitalWrite(led5,0);digitalWrite(led6,0);
  delay(500);
  }
}

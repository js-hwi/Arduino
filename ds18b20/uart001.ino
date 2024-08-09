// /*
//     아두이노, PC 간 Uart 통신
// */

// void setup(){
//     Serial.begin(9600, SERIAL_8N1); //0x06
//     Serial.begin(9600);
//     Serial.begin(9600, SERIAL_8E1);  //0x26
//     //Serial.begin(speed, config);
//     //config 생략 시 Data 8 bit, Parity 비트 x, Stop 1bit
//     //비트 수는 5 ~ 8, 패리티 비트는 O(odd), E(even), 정지비트 수는 1~2
//     //스타트비트는 무조건 하나라서 설정 x
// }


// void loop(){
//     Serial.println("Hello, world");
// }


// void serialEvent(){
//     Serial.print(Serial.readString());
// }
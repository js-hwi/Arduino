// char msg;
// unsigned long time_previous, time_current;

// void setup(){
//     time_previous = millis(); //아두이노 보드가 현재 프로그램을 돌리기 시작한 후 지난 밀리 초 숫자를 반환
//     //Serial.begin(9600, SERIAL_8N1); // 실제 사용 시...
//     // Serial.begin(9600); // PC
//     //Serial.begin(9600, SERIAL_8E1); // 예시
//     //Serial.begin(speed, config);
//     //config는 생략될 경우 Data 8bit, Parity 없음, Stop 1bit
//     // SERIAL_8E1 : 8비트, Even Parity, 정지비트수 1
//     // 비트 수는 5~8, 패리티는 O(odd), E(even), N(non), 정지비트 수는 1~2.
//     // 스타트비트는 무조건 하나라서 설정하지 않음.
// }

// void loop(){
//     // 1초에 한 번씩 'A'를 보냅니다.
//     // 선루프 상태에 따라서 보내는 데이터의 예시 
//     // millis를 이용하면 delay와 다르게 자원을 점유하지 않는다
//     time_current = millis();
//     if(time_current >= time_previous+1000){
//         time_previous = time_current;
//         msg = 'A';
//         Serial.write(msg);
//     }
// }

// void serialEvent(){
//     msg = Serial.read();
//     Serial.write(msg);
// }

// /*
//     uart 송수신 코드
// */
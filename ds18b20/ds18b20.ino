

// const int ds18b20Pin = 2; // 얘가 DQ 핀

// void setup()
// {
//     Serial.begin(9600);
// }

// void loop()
// {
//     //goto MEAS;
//     Serial.print("Serial Number: ");
//     if (!resetSensor())
//     {
//         Serial.println("No DS18B20 detected."); //센서 초기화가 안되면 출력
//         delay(1000);
//         return; //리턴하면 계속 loop를 돈다. 
//     }
//     sendCommand(0x33); //온도 센서를 초기화 센서의 고유 ROM 코드를 읽어오는 기능을 수행
//     //0x33**은 DS18B20 센서의 Read ROM 명령


//     // Read the 64-bit ROM code
//     // for (int i = 0; i < 8; i++)
//     // {
//     //     byte byteRead = readByte(); //8비트 읽어오기 
//     //     Serial.print(byteRead, HEX);
//     //     if (i < 7)
//     //         Serial.print('-'); // Print a dash between bytes
//     // }


//     byte byteRead = readByte(); //8비트 읽어온다
//     float temperature = readTemperature()/16;

//     // 온도 출력
    

//     delay(1000); // 1초 대기
    

// // MEAS:
// //     if (!resetSensor())
// //     {
// //         Serial.println("No DS18B20 detected.");
// //         delay(1000);
// //         return;
// //     }
// //     sendCommand(0xCC);
// //     sendCommand(0x44); // STARTCONVO
// //     delay(950); //12비트 해상도 대기

// //     if (!resetSensor())
// //     {
// //         Serial.println("No DS18B20 detected.");
// //         delay(1000);
// //         return;
// //     }
// //     sendCommand(0xCC);
// //     sendCommand(0xBE);

// //     for (int i = 0; i < 9; i++)
// //     {
// //         byte byteRead = readByte();
// //         Serial.print(byteRead, HEX);
// //         if (i < 7)
// //             Serial.print('-'); // Print a dash between bytes
// //     }
// //     Serial.println();
// }


// //page15 데이터 시트 참고해서 time initialization을 해줘야 한다. 
// bool resetSensor() //센서 리셋, 데이터 라인의 펄스를 reset DS18B20 센서와의 통신을 위해 필요한 1-Wire 프로토콜의 초기화 절차를 수행
// {
//     digitalWrite(ds18b20Pin, LOW); //low면 0V, HIGH는 5V, DS18B20 센서와의 통신을 위해 데이터 핀을 LOW로 설정합니다.
//     pinMode(ds18b20Pin, OUTPUT); //데이터 핀을 출력 모드로 설정하여 LOW 신호를 보낼 수 있게 합니다.

//     delayMicroseconds(480); // Hold for 480us, DS18B20 센서가 LOW 신호를 480 마이크로초동안 유지하도록 합니다. 이는 1-Wire 프로토콜에서 센서를 리셋하는 기간
//     pinMode(ds18b20Pin, INPUT); //응답을 받기 위해 데이터 핀을 입력모드로 설정.
//     delayMicroseconds(100); // DS1820센서가 응답을 할 시간을 100마이크로초 동안 대기 


//     if (digitalRead(ds18b20Pin) == LOW) //low가 되면 true 반환.
//     {
//         delayMicroseconds(380); // 펄스의 끝을 기다리기 위해 380 마이크로초 동안 대기
//         return true; //리셋이 잘 되었을 때 true값을 반환
//     } 
//     else
//     {
//         // Serial.println("Reset NG\n");   //리셋 잘못됨!!
//         return false; // No DS18B20 detected // 리셋이 안되었을 때 false를 반환
//     }
// }

// void skip()
// {
// }


// /*
//     sendCommand(byte cmd) 함수는 주어진 명령을 1바이트씩 DS18B20 센서에 전송합니다. 이 과정에서 각 비트를 시리얼로 전송하기 위해 적절한 타이밍을 맞추어 LOW와 HIGH 신호를 보냅니다.
// */
// void sendCommand(byte cmd) //온도 센서에 1-Wire 프로토콜을 사용하여 명령을 보내는 함수
// {
//     for (int i = 0; i < 8; i++) //루프를 통한 비트 전송 , 8비트(1바이트)를 순차적으로 처리 
//     {
//         delayMicroseconds(10); // 비트 전송 준비
//         if (bitRead(cmd, i)) //cmd의 i 번째 비트를 읽는다. 1이면 1을 전송, 0이면 0을 전송
//         {
//             noInterrupts(); //일단 인터럽트 발생 x
//             digitalWrite(ds18b20Pin, LOW); //LOW여야 아두이노와 온도센서가 연결.
//             pinMode(ds18b20Pin, OUTPUT); //핀을 출력모드로
//             delayMicroseconds(10);

//             digitalWrite(ds18b20Pin, HIGH);
//             interrupts();
//             delayMicroseconds(55);
//         }
//         else  //비트를 못읽어 오면 아래 구문실행.
//         {
//             noInterrupts(); //일단 인터럽트 발생 x
//             digitalWrite(ds18b20Pin, LOW);
//             pinMode(ds18b20Pin, OUTPUT);
//             delayMicroseconds(65);
//             digitalWrite(ds18b20Pin, HIGH);
//             interrupts();
//             delayMicroseconds(5);
//         }
//         // delayMicroseconds(1);       // Recovery time between bits
//         // pinMode(ds18b20Pin, INPUT); // Release the data line
//     }
// }

// byte readByte()
// {
//     byte byteRead = 0;
//     for (int i = 0; i < 8; i++)
//     {
//         noInterrupts();
//         pinMode(ds18b20Pin, OUTPUT);
//         digitalWrite(ds18b20Pin, LOW);
//         delayMicroseconds(3);

//         pinMode(ds18b20Pin, INPUT);
//         delayMicroseconds(10);
//         byteRead |= (digitalRead(ds18b20Pin) << i);
//         interrupts();
//         delayMicroseconds(53);
//     }
//     return byteRead;
// }

// int16_t readTemperature()
// {
//     // Read two bytes of temperature data
//     byte lowByte = readByte();
//     byte highByte = readByte();
//     // Combine the two bytes into a 16-bit integer
//     //int16_t temperatureData = (highByte << 8) | lowByte;
//     int16_t temperatureData = (highByte << 4) || (lowByte >> 4);

//     float temperatureCelsius = temperatureData;
//     Serial.print("Temperature: ");
//     Serial.print(temperatureCelsius);
//     Serial.println(" C");
//     return temperatureData;
// }
#include <Servo.h> // include servo library

// Define 8 Servos
Servo[] servos;

int servoPins[] = {4, 3, 5, 6, 7, 8, 9, 10};
int servoMin[8];
int servoMid[8];
int servoMax[8];


//==========================================================================================

//===== Setup ==============================================================================

void setup() {
  for (int i = 0 ; i < 8 ; i++) {
    servoMin[i] = 0;
    servoMid[i] = 90;
    servoMax[i] = 180;
  }
  activateMotors(true);
  Serial.begin(115200);

} //setup

//==========================================================================================

//== Loop ==================================================================================

void loop() {
  if (Serial.available() > 0) {
    value = Serial.read();

    switch (value) {
      case 'w':
        lastValue = 'w';
        forward();
        break;

      case 's':
        lastValue = 's';
        back();
        break;

      case 'd':
        lastValue = 'd';
        turn_right();
        break;

      case 'a':
        lastValue = 'a';
        turn_left();
        break;

      default:
        break;
    }

    delay(50);       // Pause for 50ms before executing next movement
  }
}

void activateMotor() {
  Serial.print("motor activated: ");
  Serial.println(v);
  Servo ser;

  ser.write(15);
  delay(1000);
  ser.write(90);
  delay(100);
}


void activateMotors(bool state) {
  for (int i = 0 ; i < 8 ; i++) {
    if (state) {
      servos[i].attach(servoPins[i]);
      servos[i].write(servoMid[i]);
    } else {
      servos[i].detach();
    }
  }
}

void forward() {

  // set servo positions and speeds needed to walk forward one step
  // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
  srv(180 + da, 0 + db, 120 + dc, 60 + dd, 42, 33, 33, 42, 1, 3, 1, 1);
  srv(90 + da, 30 + db, 90 + dc, 30 + dd, 6, 33, 33, 42, 3, 1, 1, 1);
  srv(90 + da, 30 + db, 90 + dc, 30 + dd, 42, 33, 33, 42, 3, 1, 1, 1);
  srv(120 + da, 60 + db, 180 + dc, 0 + dd, 42, 33, 6, 42, 1, 1, 3, 1);
  srv(120 + da, 60 + db, 180 + dc, 0 + dd, 42, 33, 33, 42, 1, 1, 3, 1);
  srv(150 + da, 90 + db, 150 + dc, 90 + dd, 42, 33, 33, 6, 1, 1, 1, 3);
  srv(150 + da, 90 + db, 150 + dc, 90 + dd, 42, 33, 33, 42, 1, 1, 1, 3);
  srv(180 + da, 0 + db, 120 + dc, 60 + dd, 42, 6, 33, 42, 1, 3, 1, 1);
  //srv(180 + da, 0 + db,  120 + dc, 60 + dd, 42,  15,  33,  42,  1,  3,  1,  1);
}

void back() {
  // set servo positions and speeds needed to walk backward one step
  // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
  srv(180, 0, 120, 60, 42, 33, 33, 42, 3, 1, 1, 1);
  srv(150, 90, 150, 90, 42, 18, 33, 42, 1, 3, 1, 1);
  srv(150, 90, 150, 90, 42, 33, 33, 42, 1, 3, 1, 1);
  srv(120, 60, 180, 0, 42, 33, 33, 6, 1, 1, 1, 3);
  srv(120, 60, 180, 0, 42, 33, 33, 42, 1, 1, 1, 3);
  srv(90, 30, 90, 30, 42, 33, 18, 42, 1, 1, 3, 1);
  srv(90, 30, 90, 30, 42, 33, 33, 42, 1, 1, 3, 1);
  srv(180, 0, 120, 60, 6, 33, 33, 42, 3, 1, 1, 1);
}

void turn_left() {
  // set servo positions and speeds needed to turn left one step
  // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
  srv(150, 90, 90, 30, 42, 6, 33, 42, 1, 3, 1, 1);
  srv(150, 90, 90, 30, 42, 33, 33, 42, 1, 3, 1, 1);
  srv(120, 60, 180, 0, 42, 33, 6, 42, 1, 1, 3, 1);
  srv(120, 60, 180, 0, 42, 33, 33, 24, 1, 1, 3, 1);
  srv(90, 30, 150, 90, 42, 33, 33, 6, 1, 1, 1, 3);
  srv(90, 30, 150, 90, 42, 33, 33, 42, 1, 1, 1, 3);
  srv(180, 0, 120, 60, 6, 33, 33, 42, 3, 1, 1, 1);
  srv(180, 0, 120, 60, 42, 33, 33, 33, 3, 1, 1, 1);
}

void turn_right() {
  // set servo positions and speeds needed to turn right one step
  // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
  srv(90, 30, 150, 90, 6, 33, 33, 42, 3, 1, 1, 1);
  srv(90, 30, 150, 90, 42, 33, 33, 42, 3, 1, 1, 1);
  srv(120, 60, 180, 0, 42, 33, 33, 6, 1, 1, 1, 3);
  srv(120, 60, 180, 0, 42, 33, 33, 42, 1, 1, 1, 3);
  srv(150, 90, 90, 30, 42, 33, 6, 42, 1, 1, 3, 1);
  srv(150, 90, 90, 30, 42, 33, 33, 42, 1, 1, 3, 1);
  srv(180, 0, 120, 60, 42, 6, 33, 42, 1, 3, 1, 1);
  srv(180, 0, 120, 60, 42, 33, 33, 42, 1, 3, 1, 1);
}

void center_servos() {
  for (int i = 0 ; i < 8 ; i++) {
    servos[i].write(servoMid[i]);
  }
}

void srv(int p11, int p21, int p31, int p41, int p12, int p22, int p32, int p42, int sp1, int sp2, int sp3, int sp4) {

  // p11: Front Left Pivot Servo
  // p21: Back Left Pivot Servo
  // p31: Back Right Pivot Servo
  // p41: Front Right Pivot Servo
  // p12: Front Left Lift Servo
  // p22: Back Left Lift Servo
  // p32: Back Right Lift Servo
  // p42: Front Right Lift Servo
  // sp1: Speed 1
  // sp2: Speed 2
  // sp3: Speed 3
  // sp4: Speed 4

  // Multiply lift servo positions by manual height adjustment
  p12 = p12 + high * 3;
  p22 = p22 + high * 3;
  p32 = p32 + high * 3;
  p42 = p42 + high * 3;

  while ((s11 != p11) || (s21 != p21) || (s31 != p31) || (s41 != p41) || (s12 != p12) || (s22 != p22) || (s32 != p32) || (s42 != p42))
  {

    // Front Left Pivot Servo
    if (s11 < p11) // if servo position is less than programmed position
    {
      if ((s11 + sp1) <= p11)
        s11 = s11 + sp1; // set servo position equal to servo position plus speed constant
      else
        s11 = p11;
    }

    if (s11 > p11) // if servo position is greater than programmed position
    {
      if ((s11 - sp1) >= p11)
        s11 = s11 - sp1; // set servo position equal to servo position minus speed constant
      else
        s11 = p11;
    }

    // Back Left Pivot Servo
    if (s21 < p21)
    {
      if ((s21 + sp2) <= p21)
        s21 = s21 + sp2;
      else
        s21 = p21;
    }

    if (s21 > p21)
    {
      if ((s21 - sp2) >= p21)
        s21 = s21 - sp2;
      else
        s21 = p21;
    }

    // Back Right Pivot Servo
    if (s31 < p31)
    {
      if ((s31 + sp3) <= p31)
        s31 = s31 + sp3;
      else
        s31 = p31;
    }

    if (s31 > p31)
    {
      if ((s31 - sp3) >= p31)
        s31 = s31 - sp3;
      else
        s31 = p31;
    }

    // Front Right Pivot Servo
    if (s41 < p41)
    {
      if ((s41 + sp4) <= p41)
        s41 = s41 + sp4;
      else
        s41 = p41;
    }

    if (s41 > p41)
    {
      if ((s41 - sp4) >= p41)
        s41 = s41 - sp4;
      else
        s41 = p41;
    }

    // Front Left Lift Servo
    if (s12 < p12)
    {
      if ((s12 + sp1) <= p12)
        s12 = s12 + sp1;
      else
        s12 = p12;
    }

    if (s12 > p12)
    {
      if ((s12 - sp1) >= p12)
        s12 = s12 - sp1;
      else
        s12 = p12;
    }

    // Back Left Lift Servo
    if (s22 < p22)
    {
      if ((s22 + sp2) <= p22)
        s22 = s22 + sp2;
      else
        s22 = p22;
    }

    if (s22 > p22)
    {
      if ((s22 - sp2) >= p22)
        s22 = s22 - sp2;
      else
        s22 = p22;
    }

    // Back Right Lift Servo
    if (s32 < p32)
    {
      if ((s32 + sp3) <= p32)
        s32 = s32 + sp3;
      else
        s32 = p32;
    }

    if (s32 > p32)
    {
      if ((s32 - sp3) >= p32)
        s32 = s32 - sp3;
      else
        s32 = p32;
    }

    // Front Right Lift Servo
    if (s42 < p42)
    {
      if ((s42 + sp4) <= p42)
        s42 = s42 + sp4;
      else
        s42 = p42;
    }

    if (s42 > p42)
    {
      if ((s42 - sp4) >= p42)
        s42 = s42 - sp4;
      else
        s42 = p42;
    }

    // Write Pivot Servo Values
    myServo1.write(s11 + da);
    myServo3.write(s21 + db);
    myServo5.write(s31 + dc);
    myServo7.write(s41 + dd);

    // Write Lift Servos Values
    myServo2.write(s12);
    myServo4.write(s22);
    myServo6.write(s32);
    myServo8.write(s42);

    delay(spd); // Delay before next movement

  }
}

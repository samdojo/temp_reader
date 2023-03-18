

struct Display {

  typedef enum Segment {
    SEG_VTR = 2, // vertical top-right
    SEG_HT = 3,  // horizontal top
    SEG_VTL = 4, // vertical top-left
    SEG_HM = 5,  // horizontal middle
    SEG_VBR = 6, // vertical bottom-right
    SEG_HB = 7,  // horizontal bottom
    SEG_VBL = 8  // vertical bottom-left
  };

  typedef enum Digit {
    DIGIT_10s = 11,
    DIGIT_1s = 12,
    DIGIT_10ths = 13
  };

  static void init() {
    pinMode(static_cast<int>(SEG_VTR), OUTPUT);
    pinMode(static_cast<int>(SEG_HT), OUTPUT);
    pinMode(static_cast<int>(SEG_VTL), OUTPUT);
    pinMode(static_cast<int>(SEG_HM), OUTPUT);
    pinMode(static_cast<int>(SEG_VBR), OUTPUT);
    pinMode(static_cast<int>(SEG_HB), OUTPUT);
    pinMode(static_cast<int>(SEG_VBL), OUTPUT);

    pinMode(static_cast<int>(DIGIT_10s), OUTPUT);
    pinMode(static_cast<int>(DIGIT_1s), OUTPUT);
    pinMode(static_cast<int>(SEG_VBL), OUTPUT);
  }

  static void inline print_digit(uint8_t num, Digit digit) {
    switch (num) {
      case 0: print_0(digit); break;
      case 1: print_1(digit); break;
      case 2: print_2(digit); break;
      case 3: print_3(digit); break;
      case 4: print_4(digit); break;
      case 5: print_5(digit); break;
      case 6: print_6(digit); break;
      case 7: print_7(digit); break;
      case 8: print_8(digit); break;
      case 9: print_9(digit); break;
      default: print_error(digit); break;
    }
    delay(10);
  }

private:

  static void inline write_segment(Segment seg, bool on) {
    digitalWrite(static_cast<int>(seg), on ? HIGH : LOW);
  }

  static void inline enable_digit(Digit digit, bool on) {
    digitalWrite(static_cast<int>(digit), on ? HIGH : LOW);
  }

  static void inline print_0(Digit digit) {
    enable_digit(digit);

    write_segment(SEG_VTR, true);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, true);
    write_segment(SEG_HM, false);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, true);
    write_segment(SEG_VBL, true);
  }

  static void inline print_1(Digit digit) {
    enable_digit(digit);

    write_segment(SEG_VTR, true);
    write_segment(SEG_HT, false);
    write_segment(SEG_VTL, false);
    write_segment(SEG_HM, false);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, false);
    write_segment(SEG_VBL, false);
  }

  static void inline print_2(Digit digit) {
    enable_digit(digit);

    write_segment(SEG_VTR, true);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, false);
    write_segment(SEG_HM, true);
    write_segment(SEG_VBR, false);
    write_segment(SEG_HB, true);
    write_segment(SEG_VBL, true);
  }

  static void inline print_3(Digit digit) {
    enable_digit(digit);
    
    write_segment(SEG_VTR, true);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, false);
    write_segment(SEG_HM, true);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, true);
    write_segment(SEG_VBL, false);
  }

  static void inline print_4(Digit digit) {
    enable_digit(digit);

    write_segment(SEG_VTR, true);
    write_segment(SEG_HT, false);
    write_segment(SEG_VTL, true);
    write_segment(SEG_HM, true);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, false);
    write_segment(SEG_VBL, false);
  }

  static void inline print_5(Digit digit) {
    enable_digit(digit);
    
    write_segment(SEG_VTR, false);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, true);
    write_segment(SEG_HM, true);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, true);
    write_segment(SEG_VBL, false);
  }

  static void inline print_6(Digit digit) {
    enable_digit(digit);

    write_segment(SEG_VTR, false);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, true);
    write_segment(SEG_HM, true);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, true);
    write_segment(SEG_VBL, true);
  }

  static void inline print_7(Digit digit) {
    enable_digit(digit);

    write_segment(SEG_VTR, true);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, false);
    write_segment(SEG_HM, false);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, false);
    write_segment(SEG_VBL, false);
  }

  static void inline print_8(Digit digit) {
    enable_digit(digit);
    
    write_segment(SEG_VTR, true);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, true);
    write_segment(SEG_HM, true);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, true);
    write_segment(SEG_VBL, true);
  }

  static void inline print_9(Digit digit) {
    enable_digit(digit);

    write_segment(SEG_VTR, true);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, true);
    write_segment(SEG_HM, true);
    write_segment(SEG_VBR, true);
    write_segment(SEG_HB, false);
    write_segment(SEG_VBL, false);
  }

  static void inline print_error(Digit digit) {
    enable_digit(digit);

    write_segment(SEG_VTR, false);
    write_segment(SEG_HT, true);
    write_segment(SEG_VTL, true);
    write_segment(SEG_HM, true);
    write_segment(SEG_VBR, false);
    write_segment(SEG_HB, true);
    write_segment(SEG_VBL, true);
  }

  static void inline enable_digit(Digit digit) {
    enable_digit(DIGIT_10s, false);
    enable_digit(DIGIT_1s, false);
    enable_digit(DIGIT_10ths, false); 

    enable_digit(digit, true);
  }

};

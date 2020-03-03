// Output pins.
static int output[] = {0, 1, 2, 3};
static int output2[] = {4, 5, 6, 7};

// 8421 code lookup table.
static int segs_encoding[][4] =
{ 
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 1, 0, 0},
  {0, 1, 0, 1},
  {0, 1, 1, 0},
  {0, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 0, 0, 1}
};
// Outputs an 8421 decimal digit on the output pins from
// base to base + 3 in big endian order.
void show(int base, int num) {
  for (int i = 0; i < 4; ++i) {
    if (segs_encoding[num][i] == 1) {
      digitalWrite(base + 3 - i , HIGH);
    } else {
      digitalWrite(base + 3 - i , LOW);
    }
  }
}
// Output a decimal value.
void show_decimal(int num) {
  show(0, num / 10);
  show(4, num % 10);
}
// the setup routine runs once when you press reset:
void setup() {
  for (int j = 4; j < 8; ++j)
    pinMode(j, OUTPUT);
  for (int i = 0; i < 4; ++i)
    pinMode(i, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  static int i = 0;
  show_decimal(i);
  delay(1000);
  // Increases the counter.
  ++i;
  if (i == 60)
    i = 0;
}

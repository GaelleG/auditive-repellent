// --------------
// | ULTRASOUND |
// --------------
// Frequencies higher than the upper audible limit of human hearing.
// Approximately 20 kHz for healthy young adults.
// Ultrasound devices operate with frequencies from 20 kHz up to several gigahertz.
// source: https://en.wikipedia.org/wiki/Ultrasound

struct HearingRange {
  char* species;
  long lo;
  long hi;
  bool enabled;
};

HearingRange HEARING_RANGE_LIST[] = {
  // {"Tuna"              ,    50,   1100, false},
  {"Chicken"           ,   125,   2000, false},
  // {"Goldfish"          ,    20,   3000, false},
  // {"Bullfrog"          ,   100,   3000, false},
  // {"Catfish"           ,    50,   4000, false},
  {"Tree frog"         ,    50,   4000, false},
  {"Canary"            ,   250,   8000, false},
  {"Cockatiel"         ,   250,   8000, false},
  {"Parakeet"          ,   200,   8500, false},
  // {"Elephant"          ,    17,  10500, false},
  {"Owl"               ,   200,  12000, false},
  {"Human"             ,    31,  19000, false},
  // {"Chinchilla"        ,    52,  33000, false},
  // {"Horse"             ,    55,  33500, false},
  // {"Cow"               ,    23,  35000, false},
  // {"Raccoon"           ,   100,  40000, false},
  // {"Sheep"             ,   125,  42500, false},
  {"Dog"               ,    64,  44000, false},
  // {"Ferret"            ,    16,  44000, false},
  {"Hedgehog"          ,   250,  45000, false},
  // {"Guinea pig"        ,    47,  49000, false},
  // {"Rabbit"            ,    96,  49000, false},
  // {"Sea lion"          ,   200,  50000, false},
  // {"Gerbil"            ,    56,  60000, false},
  // {"Opossum"           ,   500,  64000, false},
  {"Albino rat"        ,   390,  72000, true},
  {"Hooded rat"        ,   530,  75000, true},
  {"Cat"               ,    55,  77000, true},
  {"Mouse"             ,   900,  79000, true},
  {"Little brown bat"  , 10300, 115000, false},
  // {"Beluga whale"      ,  1000, 123000, false},
  // {"Bottlenose dolphin",   150, 150000, false},
  // {"Porpoise"          ,    75, 150000, false},
};
// source: https://commons.wikimedia.org/wiki/File:Animal_hearing_frequency_range.svg

int TONE_PIN = 8;
long TONE_DURATION = 1000;
unsigned long prevTime, elapsedTime, toneTimer = 0;
long toneRange[2];
long toneCurr;

void setup() {
  prevTime = millis();
  toneRange[0] = 20000;
  toneRange[1] = 77000;
  toneCurr = toneRange[0];
}

void loop() {
  elapsedTime = millis() - prevTime;
  prevTime = millis();
  toneTimer += elapsedTime;
  if (toneTimer >= TONE_DURATION) {
    toneTimer -= TONE_DURATION;
    toneCurr += 1000;
    if (toneCurr > toneRange[1]) toneCurr = toneRange[0];
    tone(TONE_PIN, toneCurr);
  }
}

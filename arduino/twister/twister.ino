
#define WIDTH 16
#define BLINK_DELAY 500
#define INIT_DELAY 1000
#define LONG_DELAY 3000

void fullBlink(int times) {
    for (int i=0; i < times; ++i) {
        PORTB ^= 0xff;
        PORTD ^= 0xff;
        _delay_ms(BLINK_DELAY);
    }
}

void set(int pos) {
    PORTB = 0xff;
    PORTD = 0xff;
    unsigned char one = 1;
    switch (pos) {
        case  0: PORTB = ~(one << 5); break;
        case  1: PORTB = ~(one << 4); break;
        case  2: PORTB = ~(one << 3); break;
        case  3: PORTB = ~(one << 2); break;

        case  7: PORTB = ~(one << 1); break;
        case  6: PORTB = ~(one << 0); break;
        case  5: PORTD = ~(one << 7); break;
        case  4: PORTD = ~(one << 6); break;

        case 11: PORTD = ~(one << 5); break;
        case 10: PORTB = ~(one << 7); break;
        case  9: PORTB = ~(one << 6); break;
        case  8: PORTD = ~(one << 4); break;

        case 15: PORTD = ~(one << 3); break;
        case 14: PORTD = ~(one << 2); break;
        case 13: PORTD = ~(one << 1); break;
        case 12: PORTD = ~(one << 0); break;
    }
}

void heartbeat(int times) {
    for (int i=0; i < times; ++i) {
        PORTB ^= 0xff;
        PORTD ^= 0xff;
        _delay_ms(10);
        PORTB ^= 0xff;
        PORTD ^= 0xff;
        _delay_ms(990);
    }
}

void setup() {
    DDRB = 0xff;
    DDRD = 0xff;
    int seed= analogRead(A0);
    fullBlink(2);
    fullBlink(2);
    for (int i=0; i<100; ++i) {
        seed += analogRead(A0);
    }
    srandom(seed);
    fullBlink(2);

}

void loop() {
    for (int i=0; i<= WIDTH * 4; ++i) {
        set(i % WIDTH );
         _delay_ms(50);
    }
    set( random() % WIDTH );
    heartbeat(5);
    fullBlink(2);
}

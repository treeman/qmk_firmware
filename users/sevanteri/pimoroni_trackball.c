#include "pimoroni_trackball.h"
#include "i2c_master.h"

#ifndef TRACKBALL_NO_MATH
#include "math.h"
#   ifndef TRACKBALL_ANGLE_OFFSET
#   define TRACKBALL_ANGLE_OFFSET 0
#   endif
#endif

#ifndef TRACKBALL_ORIENTATION
#   define TRACKBALL_ORIENTATION 0
#endif

void trackball_init(void) {
    i2c_init();
#ifdef TRACKBALL_INTERRUPT_PIN
    setPinInput(TRACKBALL_INTERRUPT_PIN);
    writePinLow(TRACKBALL_INTERRUPT_PIN);
    uint8_t data[] = {REG_INTERRUPT_PIN, MASK_INTERRUPT_PIN_ENABLE};
    i2c_transmit(TRACKBALL_WRITE, data, 2, TB_I2C_TIMEOUT);
#endif
}

bool trackball_get_interrupt(void) {
#ifndef TRACKBALL_INTERRUPT_PIN
    uint8_t data[1] = {};
    i2c_readReg(TRACKBALL_WRITE, REG_INTERRUPT_PIN, data, 1, TB_I2C_TIMEOUT);

    return data[0] & MASK_INTERRUPT_TRIGGERED;
#else
    return !readPin(TRACKBALL_INTERRUPT_PIN);
#endif
}

void trackball_set_rgbw(uint8_t red, uint8_t green, uint8_t blue, uint8_t white) {
    uint8_t data[] = {0x00, red, green, blue, white};
    i2c_transmit(TRACKBALL_WRITE, data, 5, TB_I2C_TIMEOUT);
}

void trackball_read_state(uint8_t* data, uint16_t size_of_data) {
    i2c_readReg(TRACKBALL_WRITE, REG_LEFT, data, size_of_data, TB_I2C_TIMEOUT);
}

trackball_state_t trackball_get_state(void) {
    // up down left right button
    uint8_t s[5] = {};
    trackball_read_state(s, 5);

    trackball_state_t state = {
#if TRACKBALL_ORIENTATION == 0
        // Pimoroni text is up
        .y = s[0] - s[1],
        .x = s[3] - s[2],
#elif TRACKBALL_ORIENTATION == 1
        // Pimoroni text is right
        .y = s[3] - s[2],
        .x = s[1] - s[0],
#elif TRACKBALL_ORIENTATION == 2
        // Pimoroni text is down
        .y = s[1] - s[0],
        .x = s[2] - s[3],
#else
        // Pimoroni text is left
        .y = s[2] - s[3],
        .x = s[0] - s[1],
#endif
        .button_down = s[4] & 0x80,
        .button_triggered = s[4] & 0x01,
    };

#ifndef TRACKBALL_NO_MATH
    state.angle_rad = atan2(state.y, state.x) + TRACKBALL_ANGLE_OFFSET;
    state.vector_length = sqrt(pow(state.x, 2) + pow(state.y, 2));
    state.raw_x = state.x;
    state.raw_y = state.y;
    state.x = (int16_t)(state.vector_length * cos(state.angle_rad));
    state.y = (int16_t)(state.vector_length * sin(state.angle_rad));
#endif

    return state;
}

void trackball_sleep(void) {
    /* not sure how this is supposed to work */
    uint8_t data[] = {REG_CTRL, MSK_CTRL_FWRITE | MSK_CTRL_SLEEP};
    i2c_transmit(TRACKBALL_WRITE, data, 2, TB_I2C_TIMEOUT);
}

void trackball_set_brightness(uint8_t brightness) {
    uint8_t data[4] = {};
    i2c_readReg(TRACKBALL_WRITE, REG_RED, data, 4, TB_I2C_TIMEOUT);
    for (int i=0; i<4; i++) {
        if (data[i]) {
            data[i] = brightness;
        }
    }
    i2c_writeReg(TRACKBALL_WRITE, REG_RED, data, 4, TB_I2C_TIMEOUT);
}

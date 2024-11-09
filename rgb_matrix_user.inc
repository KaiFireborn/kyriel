RGB_MATRIX_EFFECT(CUSTOM_REACTIVE)



#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static const HSV predefined_hsvs[] = {
    {34, 221, 255},
    {2, 215, 255},
    {3, 182, 255},
    {202, 4, 255},
    {15, 144, 255}
};

static HSV CUSTOM_REACTIVE_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;

    // hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
    // hsv.s = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
    hsv.h = 34;
    hsv.s = 221;

    hsv.v = qadd8(hsv.v, 255 - effect);

    return hsv;
}

bool CUSTOM_REACTIVE(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &CUSTOM_REACTIVE_math);
}
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
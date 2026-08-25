import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import display
from esphome.const import CONF_ID
from esphome import pins

jc4827_ns = cg.esphome_ns.namespace("jc4827")
JC4827Display = jc4827_ns.class_("JC4827Display", display.DisplayBuffer)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(JC4827Display),
    cv.Optional("cs_pin"): pins.gpio_output_pin_schema,
    cv.Optional("dc_pin"): pins.gpio_output_pin_schema,
    cv.Optional("reset_pin"): pins.gpio_output_pin_schema,
    cv.Optional("backlight_pin"): pins.gpio_output_pin_schema,
}).extend(display.DISPLAY_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield display.register_display(var, config)

    if "cs_pin" in config:
        cs = yield cg.gpio_pin_expression(config["cs_pin"])
        cg.add(var.set_cs_pin(cs))
    if "dc_pin" in config:
        dc = yield cg.gpio_pin_expression(config["dc_pin"])
        cg.add(var.set_dc_pin(dc))
    if "reset_pin" in config:
        rst = yield cg.gpio_pin_expression(config["reset_pin"])
        cg.add(var.set_reset_pin(rst))
    if "backlight_pin" in config:
        bl = yield cg.gpio_pin_expression(config["backlight_pin"])
        cg.add(var.set_backlight_pin(bl))

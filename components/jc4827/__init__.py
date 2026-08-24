import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import display

DEPENDENCIES = ["i2c"]
AUTO_LOAD = ["display", "i2c"]

jc4827_ns = cg.esphome_ns.namespace("jc4827")
JC4827 = jc4827_ns.class_("JC4827", display.DisplayBuffer)

CONFIG_SCHEMA = display.FULL_DISPLAY_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(JC4827),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[cv.CONF_ID])
    await display.register_display(var, config)

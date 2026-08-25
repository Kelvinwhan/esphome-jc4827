import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import display
from esphome.const import CONF_ID

jc4827_ns = cg.esphome_ns.namespace('jc4827')
JC4827Display = jc4827_ns.class_('JC4827Display', display.DisplayBuffer)
JC4827Touch = jc4827_ns.class_('JC4827Touch', cg.Component)

# Schema for display
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(JC4827Display),
})

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield display.register_display(var, config)

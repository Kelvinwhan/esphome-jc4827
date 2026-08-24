import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import core

# Create a namespace for your component
jc4827_ns = cg.esphome_ns.namespace('jc4827')
JC4827 = jc4827_ns.class_('JC4827', cg.Component)

# Define YAML schema
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(JC4827),
    cv.Optional("display"): cv.use_id(JC4827),
})

# Code generation hook
async def to_code(config):
    var = cg.new_Pvariable(config[core.CONF_ID])
    await cg.register_component(var, config)

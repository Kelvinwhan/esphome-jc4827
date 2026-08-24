import esphome.codegen as cg
import esphome.config_validation as cv

jc4827_ns = cg.esphome_ns.namespace('jc4827')
JC4827 = jc4827_ns.class_('JC4827', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(JC4827),
})

async def to_code(config):
    var = cg.new_Pvariable(config[cv.CONF_ID])
    await cg.register_component(var, config)

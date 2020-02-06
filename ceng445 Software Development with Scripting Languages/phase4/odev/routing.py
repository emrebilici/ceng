from channels.routing import route, ProtocolTypeRouter
from rulebasedgame.consumers import ws_connect, ws_disconnect


channel_routing = [
    route('websocket.connect', ws_connect),
    route('websocket.disconnect', ws_disconnect),
]

application = ProtocolTypeRouter({
    # (http->django views is added by default)
})
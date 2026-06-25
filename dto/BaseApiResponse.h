//
// Created by Emmanuel Addo-Odame on 25/06/2026.
//

#ifndef MAGMANETAPI_BASEAPIRESPONSE_H
#define MAGMANETAPI_BASEAPIRESPONSE_H
#include <json/json.h>
#include <string>

namespace magma_net::dto {

    class BaseApiResponse {
    public:
        Json::Value result;
        std::string targetUrl;
        std::string message;
        bool success;
        Json::Value error;

        BaseApiResponse() : success(false) {}

        [[nodiscard]]
        Json::Value toJson() const {
            Json::Value json;
            json["result"] = result;
            json["targetUrl"] = targetUrl;
            json["message"] = message;
            json["success"] = success;
            json["error"] = error;
            return json;
        }
    };
}
#endif //MAGMANETAPI_BASEAPIRESPONSE_H
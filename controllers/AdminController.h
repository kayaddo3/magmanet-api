#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class AdminController : public drogon::HttpController<AdminController>
{
  public:
  static constexpr const char *PREFIX = "/api/v1/admin/";
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(AdminController::getAll, std::string(PREFIX) + "get-all", Get, Options);
  ADD_METHOD_TO(AdminController::getStats, std::string(PREFIX) + "get-", Get, Options);
  METHOD_LIST_END

  Task<HttpResponsePtr> getAll(HttpRequestPtr req);
  Task<HttpResponsePtr> getAll(HttpRequestPtr req);
};

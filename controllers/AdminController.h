#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class AdminController : public drogon::HttpController<AdminController>
{
  public:
  static constexpr const char *PREFIX = "/api/v1/admin/";
  METHOD_LIST_BEGIN
  //plans
    ADD_METHOD_TO(AdminController::getInternetPlans, std::string(PREFIX) + "get-internet-plans", Get, Options);
    ADD_METHOD_TO(AdminController::createInternetPlan, std::string(PREFIX) + "create-internet-plan", Post, Options);
    ADD_METHOD_TO(AdminController::updateInternetPlan, std::string(PREFIX) + "update-internet-plan/{1}", Put, Options);
    ADD_METHOD_TO(AdminController::deleteInternetPlan, std::string(PREFIX) + "delete-internet-plan/{1}", Delete, Options);
  //customers
  ADD_METHOD_TO(AdminController::getAllCustomers, std::string(PREFIX) + "get-all-customers", Get, Options);
  ADD_METHOD_TO(AdminController::createCustomer, std::string(PREFIX) + "create-customer", Post, Options);
  ADD_METHOD_TO(AdminController::updateCustomer, std::string(PREFIX) + "update-customer/{1}", Put, Options);
  ADD_METHOD_TO(AdminController::deleteCustomer, std::string(PREFIX) + "delete-customer/{1}", Delete, Options);
  //subscription
  ADD_METHOD_TO(AdminController::updateCustomerBalance, std::string(PREFIX) + "update-customer-balance/{1}", Post, Options);

  METHOD_LIST_END

  Task<HttpResponsePtr> getInternetPlans(HttpRequestPtr req);
  Task<HttpResponsePtr> createInternetPlan(HttpRequestPtr req);
  Task<HttpResponsePtr> updateInternetPlan(HttpRequestPtr req, const std::string &planId);
  Task<HttpResponsePtr> deleteInternetPlan(HttpRequestPtr req, const std::string &planId);

  //customers

  Task<HttpResponsePtr> getAllCustomers(HttpRequestPtr req);
  Task<HttpResponsePtr> createCustomer(HttpRequestPtr req);
  Task<HttpResponsePtr> updateCustomer(HttpRequestPtr req, const std::string &customerId);
  Task<HttpResponsePtr> deleteCustomer(HttpRequestPtr req, const std::string &customerId);
  Task<HttpResponsePtr> updateCustomerBalance(HttpRequestPtr req, const std::string &customerId);


};

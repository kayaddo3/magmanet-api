#include "AdminController.h"
#include "../dto/BaseApiResponse.h"

using namespace magma_net::dto;

// ─── Internet Plans ───────────────────────────────────────────────────────────

Task<HttpResponsePtr> AdminController::getInternetPlans(HttpRequestPtr req) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Internet plans retrieved successfully";

    Json::Value plans(Json::arrayValue);

    Json::Value plan1;
    plan1["id"] = "plan-001";
    plan1["name"] = "Basic";
    plan1["speedMbps"] = 10;
    plan1["pricePerMonth"] = 29.99;

    Json::Value plan2;
    plan2["id"] = "plan-002";
    plan2["name"] = "Standard";
    plan2["speedMbps"] = 50;
    plan2["pricePerMonth"] = 49.99;

    Json::Value plan3;
    plan3["id"] = "plan-003";
    plan3["name"] = "Premium";
    plan3["speedMbps"] = 200;
    plan3["pricePerMonth"] = 89.99;

    plans.append(plan1);
    plans.append(plan2);
    plans.append(plan3);

    apiResponse.result = plans;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k200OK);
    co_return resp;
}


Task<HttpResponsePtr> AdminController::createInternetPlan(HttpRequestPtr req) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Internet plan created successfully";

    Json::Value createdPlan;
    createdPlan["id"] = "plan-004";
    createdPlan["name"] = "Ultra";
    createdPlan["speedMbps"] = 500;
    createdPlan["pricePerMonth"] = 129.99;

    apiResponse.result = createdPlan;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k201Created);
    co_return resp;
}


Task<HttpResponsePtr> AdminController::updateInternetPlan(HttpRequestPtr req, const std::string &planId) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Internet plan updated successfully";

    Json::Value updatedPlan;
    updatedPlan["id"] = planId;
    updatedPlan["name"] = "Updated Plan";
    updatedPlan["speedMbps"] = 100;
    updatedPlan["pricePerMonth"] = 69.99;

    apiResponse.result = updatedPlan;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k200OK);
    co_return resp;
}


Task<HttpResponsePtr> AdminController::deleteInternetPlan(HttpRequestPtr req, const std::string &planId) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Internet plan with id '" + planId + "' deleted successfully";

    Json::Value deletedInfo;
    deletedInfo["deletedPlanId"] = planId;
    apiResponse.result = deletedInfo;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k200OK);
    co_return resp;
}


// ─── Customers ────────────────────────────────────────────────────────────────

Task<HttpResponsePtr> AdminController::getAllCustomers(HttpRequestPtr req) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Customers retrieved successfully";

    Json::Value customers(Json::arrayValue);

    Json::Value customer1;
    customer1["id"] = "cust-001";
    customer1["name"] = "Alice Johnson";
    customer1["email"] = "alice@example.com";
    customer1["planId"] = "plan-001";
    customer1["balance"] = 150.00;

    Json::Value customer2;
    customer2["id"] = "cust-002";
    customer2["name"] = "Bob Smith";
    customer2["email"] = "bob@example.com";
    customer2["planId"] = "plan-002";
    customer2["balance"] = 75.50;

    customers.append(customer1);
    customers.append(customer2);

    apiResponse.result = customers;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k200OK);
    co_return resp;
}


Task<HttpResponsePtr> AdminController::createCustomer(HttpRequestPtr req) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Customer created successfully";

    Json::Value newCustomer;
    newCustomer["id"] = "cust-003";
    newCustomer["name"] = "Carol White";
    newCustomer["email"] = "carol@example.com";
    newCustomer["planId"] = "plan-003";
    newCustomer["balance"] = 0.00;

    apiResponse.result = newCustomer;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k201Created);
    co_return resp;
}


Task<HttpResponsePtr> AdminController::updateCustomer(HttpRequestPtr req, const std::string &customerId) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Customer updated successfully";

    Json::Value updatedCustomer;
    updatedCustomer["id"] = customerId;
    updatedCustomer["name"] = "Updated Customer Name";
    updatedCustomer["email"] = "updated@example.com";
    updatedCustomer["planId"] = "plan-002";

    apiResponse.result = updatedCustomer;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k200OK);
    co_return resp;
}


Task<HttpResponsePtr> AdminController::deleteCustomer(HttpRequestPtr req, const std::string &customerId) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Customer with id '" + customerId + "' deleted successfully";

    Json::Value deletedInfo;
    deletedInfo["deletedCustomerId"] = customerId;
    apiResponse.result = deletedInfo;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k200OK);
    co_return resp;
}


// ─── Subscription / Balance ───────────────────────────────────────────────────

Task<HttpResponsePtr> AdminController::updateCustomerBalance(HttpRequestPtr req, const std::string &customerId) {
    BaseApiResponse apiResponse;
    apiResponse.success = true;
    apiResponse.message = "Customer balance updated successfully";

    Json::Value balanceInfo;
    balanceInfo["customerId"] = customerId;
    balanceInfo["newBalance"] = 200.00;
    balanceInfo["previousBalance"] = 75.50;

    apiResponse.result = balanceInfo;

    auto resp = HttpResponse::newHttpJsonResponse(apiResponse.toJson());
    resp->setStatusCode(k200OK);
    co_return resp;
}

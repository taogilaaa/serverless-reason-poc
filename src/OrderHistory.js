// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Knex = require("bs-knex/src/Knex.bs.js");
var Curry = require("bs-platform/lib/js/curry.js");
var KnexConnection$ServerlessReason = require("./KnexConnection.js");

function makeResult(data) {
  return {
          statusCode: 200,
          body: {
            data: data,
            statusCode: "DATA_RETRIEVED",
            statusText: "Data retrieved successfully"
          }
        };
}

function dataMall(payload, param, callback) {
  var match = payload.name;
  var nameQuery = match !== undefined ? "%" + (match + "%") : "%%";
  return Knex.fromTable("data_mall", KnexConnection$ServerlessReason.knex).where("nama_mall", "like", nameQuery).then((function (results) {
                  return Promise.resolve(makeResult(results));
                })).then((function (response) {
                return Curry._2(callback, null, response);
              }));
}

function now(_event, param, callback) {
  console.log(_event);
  console.log(_event.company_name);
  return KnexConnection$ServerlessReason.knex.raw("SELECT NOW();").then((function (rawResult) {
                    var match = rawResult.rows;
                    if (match !== undefined) {
                      return Promise.resolve(match);
                    } else {
                      return Promise.resolve(/* array */[]);
                    }
                  })).then((function (results) {
                  return Promise.resolve(makeResult(results));
                })).then((function (response) {
                return Curry._2(callback, null, response);
              }));
}

exports.makeResult = makeResult;
exports.dataMall = dataMall;
exports.now = now;
/* KnexConnection-ServerlessReason Not a pure module */

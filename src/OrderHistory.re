open Knex;

[@bs.send.pipe: queryBuilder]
external whereLike: (string, string, string) => queryBuilder = "where";

let makeResult = data => {
  "statusCode": 200,
  "body": {
    "data": data,
    "statusCode": "DATA_RETRIEVED",
    "statusText": "Data retrieved successfully",
  },
};

let dataMall = (payload, _, callback) => {
  let nameQuery =
    switch (payload##name) {
    | None => "%%"
    | Some(name) => "%" ++ name ++ "%"
    };

  KnexConnection.knex
  |> fromTable("data_mall")
  |> whereLike("nama_mall", "like", nameQuery)
  |> toPromise
  |> Js.Promise.then_(results => results->makeResult->Js.Promise.resolve)
  |> Js.Promise.then_(response => callback(Js.Nullable.null, response));
};

let now = (_event, _, callback) =>
  KnexConnection.knex
  |> raw("SELECT NOW();")
  |> Js.Promise.then_(rawResult =>
       switch (rawResult##rows) {
       | None => Js.Promise.resolve([||])
       | Some(rows) => Js.Promise.resolve(rows)
       }
     )
  |> Js.Promise.then_(results => results->makeResult->Js.Promise.resolve)
  |> Js.Promise.then_(response => callback(Js.Nullable.null, response));

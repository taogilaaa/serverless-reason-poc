type jsobject = {. "message": string};

[@bs.scope "JSON"] [@bs.val] external stringify: jsobject => 'a = "stringify";

let hello = (_event, _context, callback) => {
  Js.log(_event);
  Js.log(_event##asda);
  let body = {"message": "Hello from Reason!"};
  let response = {"statusCode": 200, "body": stringify(body)};

  callback(. Js.Nullable.null, response);
};

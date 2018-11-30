let (toOption, getWithDefault) = (
  Js.Nullable.toOption,
  Js.Option.getWithDefault,
);

[@bs.val] external user: string = "process.env.DATABASE_USERNAME";
[@bs.val] external password: string = "process.env.DATABASE_PASSWORD";
[@bs.val] external host: string = "process.env.DATABASE_HOST";
[@bs.val] external port: string = "process.env.DATABASE_PORT";
[@bs.val] external database: string = "process.env.DATABASE_NAME";

let connection =
  KnexConfig.Connection.make(~user, ~password, ~host, ~port, ~database, ());

let pool = KnexConfig.Pool.make(~min=0, ~max=5, ~idleTimeoutMillis=1000, ());

let config =
  KnexConfig.make(
    ~client="pg",
    ~connection,
    ~pool,
    ~acquireConnectionTimeout=2000,
    (),
  );

let knex = Knex.make(config);

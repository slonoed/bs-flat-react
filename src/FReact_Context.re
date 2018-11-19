module Element = FReact_Element;

module type Value = {
  type t;
  let defaultValue: option(t);
};

module Make = (Value: Value) => {
  type props = {value: Value.t};

  module ProviderProps = {
    [@bs.deriving abstract]
    type t = {value: Value.t};
  };

  [@bs.deriving abstract]
  type context = {
    [@bs.as "Provider"]
    provider: ProviderProps.t => Element.t,
  };

  [@bs.module "react"]
  external createContext: Js.undefined('a) => context = "createContext";

  let defaultJsValue =
    switch (Value.defaultValue) {
    | Some(s) => Js.Undefined.return(s)
    | None => Js.undefined
    };
  let context = createContext(defaultJsValue);

  [@bs.module "react"] external useContext: context => Value.t = "useContext";

  /* API */
  let provider = props => {
    let provider = context |> providerGet;
    let pprops = ProviderProps.t(~value=props.value);
    let children = Element.extractChildren(props);
    Element.rawCreateElement(provider, pprops, Array.of_list([children]));
  };
  let use = () => useContext(context);
};

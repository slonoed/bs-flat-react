[@bs.module "react"] external useState: 'a => ('a, 'a => unit) = "";

[@bs.module "react"]
external useEffectRaw: (unit => Js.undefined(unit)) => unit = "useEffect";

let useEffect = effect =>
  useEffectRaw(() => {
    effect();
    Js.undefined;
  });

module DomRef = {
  [@bs.deriving abstract]
  type t = {current: option(Dom.node)};
};

[@bs.module "react"] external useDomRef: unit => DomRef.t = "useRef";

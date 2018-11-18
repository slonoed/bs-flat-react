[@bs.module "react"] external useState: 'a => ('a, 'a => unit) = "";

[@bs.module "react"]
external useEffectRaw: (unit => Js.undefined(unit)) => unit = "useEffect";

let useEffect = effect =>
  useEffectRaw(() => {
    effect();
    Js.undefined;
  });

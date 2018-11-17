
let container = () => {
    open Z;

    let (value, setValue) = Hooks.useState("test");
    Hooks.useEffect(() => {
        Js.log(value);
    });
    let onChange = event => setValue(ReactEvent.Form.target(event)##value);

    t("div", props(), [
        t("input", props(~value, ~onChange,()), []),
        t("span", props(), [
            text(value)
        ])
    ])
    
};

let target = [%raw "document.getElementById('app')"];

Z.render(Z.r(container, (), []), target);



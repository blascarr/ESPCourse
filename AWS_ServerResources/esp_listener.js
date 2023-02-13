/*
    Project created by Blascarr from ZMS
    ESP Listener
*/

if (!!window.EventSource) {
    var source = new EventSource('/esp_events');
    source.addEventListener('open', function (e) {console.log(
        "Events Connected");
    }, false);

    source.addEventListener('error', function (e) {
        if (e.target.readyState != EventSource.OPEN) {
            console.log("Events Disconnected");
        }
    }, false);

    //Bot Position
    source.addEventListener('esp_data', function (e) {
        let obj = JSON.parse(e.data);
        console.log(obj);
        
        console.log(obj.x);
        console.log(obj.y); 
        console.log(obj.theta); 
        const HTML_ELEMENT = document.createElement("p");
        HTML_ELEMENT.innerHTML = "obj.x: "+obj.x+ " - obj.y  : "+ obj.y + " - obj.theta: "+ obj.theta;
        document.body.appendChild(HTML_ELEMENT);
    }, false)

};
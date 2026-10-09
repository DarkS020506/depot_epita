document.addEventListener('DOMContentLoaded', function() {
    const colorInput = document.getElementById('colorInput');
    const textToColor = document.getElementById('textToColor');

    colorInput.addEventListener('input', function() {
        const colorValue = colorInput.value.trim();
        textToColor.style.color = colorValue;
    });
});


function myCallback(){
    console.log('test');
}
function myEvent(Callback){
    if (Math.random()>0.5){
        Callback()
    }
}
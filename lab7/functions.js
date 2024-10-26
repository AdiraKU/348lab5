
function alter_paragraph() {
    var border_R = document.getElementById("border_R").value;
    var border_G = document.getElementById("border_G").value;
    var border_B = document.getElementById("border_B").value;
    var border_width = document.getElementById("border_width").value;
    var background_R = document.getElementById("background_R").value;
    var background_G = document.getElementById("background_G").value;
    var background_B = document.getElementById("background_B").value;

    var paragraph = document.getElementById("paragraph");
    paragraph.style.borderColor = `rgb(${border_R},${border_G},${border_B})`;
    paragraph.style.borderWidth = border_width
    paragraph.style.backgroundColor = `rgb(${background_R},${background_G},${background_B})`;
}

function validate() {
    var p1 = document.getElementById("p1").value;
    var p2 = document.getElementById("p2").value;


    if (p1.length < 8) {
        alert("The length of the first password is less than 8 letters")
    } else if (p2.length < 8) {
        alert("The length of the second password is less than 8 letters")
    } else if (p1 != p2) {
        alert("The passwords dont match")
    } else {
        alert("Everything is good")
    }
}

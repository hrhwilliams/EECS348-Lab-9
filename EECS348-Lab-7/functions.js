function alert_paragraph_color() {
    const border_red = document.getElementById("border_R").value || 0;
    const border_green = document.getElementById("border_G").value || 0;
    const border_blue = document.getElementById("border_B").value || 0;

    const border_width = document.getElementById("border_width").value || 0;

    const bg_red = document.getElementById("bg_R").value || 0;
    const bg_green = document.getElementById("bg_G").value || 0;
    const bg_blue = document.getElementById("bg_B").value || 0;

    var paragraph = document.getElementById("paragraph");
    paragraph.style.backgroundColor = `rgb(${bg_red}, ${bg_green}, ${bg_blue})`;
    paragraph.style.borderColor = `rgb(${border_red}, ${border_green}, ${border_blue})`;
    paragraph.style.borderWidth = border_width;
}

function validate() {
    if (document.getElementById("pass1").value == document.getElementById("pass2").value) {
        alert("Passwords match.");
    } else {
        alert("Passwords do not match!");
    }
}

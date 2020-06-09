function carregar() {
    var msg = window.document.getElementById('msg')
    var img = window.document.getElementById('img')
    var data = new Date()
    var hora = data.getHours()
    msg.innerHTML = `Agora são ${hora} horas`

    if (hora < 12 ) {
        //Bom dia
        document.body.style.background = '#498201'
        img.src = 'fotomanha.png'
    }
    else if(hora >= 12 && hora <= 18) {
        //Boa tarde
        img.src = 'fototarde.png'
        document.body.style.background = '#fcbf17'
    }
    else {
        //Boa noite
        img.src = 'fotonoite.png'
        document.body.style.background = '#a285bf'
    }
}





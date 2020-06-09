function gerar_tabuada() {
    var txtnum = window.document.getElementById('txtnum')
    var lista = window.document.getElementById('lista')
    
    var num = Number(txtnum.value)
    
    if (txtnum.value == '') {
        window.alert('Porfavor digite um numero')
    }
    else {
        lista.innerHTML = ''
        for (var i = 1; i <= 10; i++ ) {
            var option = window.document.createElement('option')
            option.innerHTML = `${num} x ${i} = ${(num*i)}`
            lista.appendChild(option)
        }
    }
}
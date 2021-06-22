

let moves_zeros_to_begining = (v) => {
    if(v.length < 1) return;

    let r = v.length-1;
    let w = v.length-1;

    while(r>=0){
        if(v[r] !== 0){
            v[w] = v[r];
            w--;
        }
        r--;
    }

    while(w>=0){
        v[w] = 0;
        w--;
    }
}

let v = [1, 10, 20, 0, 59, 63, 0, 88, 0];
 moves_zeros_to_begining(v);
 console.log(v);
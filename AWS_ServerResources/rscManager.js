

const remote_rsc = "https://espcourse.s3.eu-west-3.amazonaws.com/espcourse.remote.config.json";

rscManager = async ()=>{
    await fetch(remote_rsc)
        .then(res => res.json())
        .then(async out =>{
            out.links.forEach( el =>{
                addCSS(el );
            });
            sourceManager( out );

            out.scripts.forEach( el =>{
                addScript( el );
            });
            return out ;
        })
        .catch(err => console.log('Error:', err));
}

sourceManager = async ( sources ) =>{
    sources.links.forEach( el =>{
        addCSS(el );
    })
    config_json = sources.config_json;
    config_shape = sources.config_shape;
}

addScript = async( script )=>{
    await checkResource( script, appendScript );
}

addCSS = ( CSSFileName )=>{
    checkResource( CSSFileName, appendCSS );
}

checkResource = async( resource, fn )=>{
    await fetch( resource , { method: 'HEAD', cache: 'reload' })
        .then(res => {
            if (res.ok) {
                
                console.log('Resource Exist -' + resource  + ' Status : '+ res.status);
                const rscToLoad = fn( resource );
                document.head.append(rscToLoad);
            } else {
                console.log('Resource does not exist - '+ resource + ' Status Error: '+ res.status+ ' ResOK : '+ res.ok);
            }
        }).catch(err => console.log('Error:', err));
}

appendScript = ( srcFileName ) =>{
    const scriptToLoad = document.createElement('script');
    scriptToLoad.src = srcFileName;
    return scriptToLoad;
}

appendCSS = ( srcFileName ) =>{
    const linkToLoad = document.createElement('link');
    linkToLoad.rel = 'stylesheet';
    linkToLoad.type = 'text/css';
    linkToLoad.href = srcFileName;
    return linkToLoad;
}

window.addEventListener("load", (event) => {
    rscManager();
});
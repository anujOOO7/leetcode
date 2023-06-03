/**
 * @param {Array} arr
 * @return {Matrix}
 */
function flatten(object){
    const result = []
    for (const key of Object.keys(object)) {
        if (typeof object[key] === 'object' && object[key] !== null) {
            const flatChild = flatten(object[key]);
            for (const childKey of Object.keys(flatChild)) {
                result[`${key}.${childKey}`] = flatChild[childKey];
            }
        } else {
            result[key] = object[key];
        }
    }

    return result;
}




var jsonToMatrix = function(arr) {
    arr=arr.map(flatten)
    const keys = new Set(arr.map(Object.keys).flat())
    const col= [...keys].sort();
    const result = new Array(arr.length+1).fill().map(_ => new Array(col.length));
    result[0] = col;
    for(var i=0; i in arr; i++)
    {
        for(var j=0;j in col;j++)
        {
            const key=col[j];
            const value=arr[i][key];
            if(value === undefined) 
                result[i+1][j] = '';
            else
                result[i+1][j] = value;
        }
    }
    return result;
};
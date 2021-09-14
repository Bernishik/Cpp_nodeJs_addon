const bubleSort = require('bindings')('sort')
const bubbleSort = (array:number[]): number[] =>{
    const arr: number[] = [...array]
    const length:number = arr.length

    for (let iteration = 0; iteration < length -1 ; iteration++ ){
        for (let i = length-1; i > iteration; i--){
            if (arr[i-1] > arr[i]){
                const tmp = arr[i-1]
                arr[i-1] = arr[i]
                arr[i] = tmp
            }
        }
    }
    return arr
}
let array1 = [1,5,6,2,1,9,4,23,42,3,5,6,2,324,2,6434,5,34,43,46]
const randomArray = (length:number, max:number) => [...new Array(length)]
    .map(() => Math.round(Math.random() * max));
array1 =  randomArray(100000, 10000)

console.time("js bubble sort")
let jsOutput = bubbleSort(array1)
console.timeEnd("js bubble sort")
console.log("js out: ", jsOutput)


console.time("C++ bubble sort")
let output= bubleSort.bubbleSort(array1)
console.timeEnd("C++ bubble sort")

console.log("C++ output " , output)
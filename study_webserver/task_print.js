//콜백
const arr = [20, 10, 30];

function callback_print(num, print) {
  setTimeout(() => print(num));
}

function print(num) {
  console.log(num);
}

callback_print(arr[1], print);
callback_print(arr[0], print);
callback_print(arr[2], print);
arr.forEach((element) => callback_print(element, print));


//promise
function promise_print(num) {
  return new Promise((resolve, reject) => {
    resolve(num)
  })
}

promise_print(arr[1])
  .then(console.log);
promise_print(arr[0])
  .then(console.log);
promise_print(arr[2])
  .then(console.log);
arr.forEach((element) => promise_print(element)
  .then(console.log));


//async & await
async function asyncprint(num) {
  await console.log(num);
}

asyncprint(arr[1]);
asyncprint(arr[0]);
asyncprint(arr[2]);
arr.forEach((element) => asyncprint(element));





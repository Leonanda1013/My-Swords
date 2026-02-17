function DoSomething() {}

const DoSomething = () => {};

// ternary operation

let suka = mood === "happy" ? "I am happy" : "I am sad";

//  map filter

// map digunakan untuk mengubah setiap elemen dalam array menjadi bentuk yang baru

const numbers = [1, 2, 3, 4, 5];

const squaredNumbers = numbers.map((number) => number * number);

// filter digunakan untuk menyaring elemen dalam array berdasarkan kondisi tertentu
const evenNumbers = numbers.filter((number) => number % 2 === 0);

// reduce digunakan untuk mengakumulasi nilai dari elemen dalam array menjadi satu nilai tunggal
const sum = numbers.reduce((accumulator, currentValue) => accumulator + currentValue, 0);

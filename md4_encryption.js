const readline = require('readline');
var md4 = require('js-md4');

const rl = readline.createInterface({
  input: process.stdin
});

rl.on('line', (input) => {
  if (md4(input) == "7a769aebe2b177f483b1debb8c409039") {
    console.log(`correct!: ${input}`);
  }
  else {
    console.log('false');
  }
  
  rl.close();
});


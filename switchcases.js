// example 1

switch (num) {
    case 1:
        x();
        break;
    case 2:
        y();
        break;
    case 3:
        z();
        break;
    default:
        err();
}

// example 2

const cases = {
    1: x,
    2: y,
    3: z
};

if (cases[num]) {
    cases[num]();
}

// example 3

const tokens = [
	'dist1','dist2','dist3',
	'mix1','mix2', 'mix3'
]

let context = "";
for(let i=0, token; (token = tokens[i]); i++) { // unsafe, but oh well
	switch(token) {
		case 'dist1': 
			context = x(); 
			break;
		case 'dist2': 
			context = y(); 
			break;
		case 'dist3': 
			context = z(); 			
			break;
		case 'mix1':
		case 'mix2':
		case 'mix3': 
			context = mix(); 
			break;
		default:
			err();
			break;
	}
}

// example 4

function x(context){ return context; }
function y(context){ return context; }
function z(context){ return context; }
 
const cases = {
    1: x,
    2: y,
    3: z
};
 
if (cases[num]) {
    context = cases[num](context);
}

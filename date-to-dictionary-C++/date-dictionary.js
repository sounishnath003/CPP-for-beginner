/*
-----------------------------------
::Coding Question::
-----------------------------------

Write an efficent function that computes the dictionary missing dates values,
like -

Input is:
------
2 // no. of dates
2019-01-01 100
2019-01-04 115

Output:
-------
2019-01-01:100
2019-01-02:105
2019-01-03:110
2019-01-04:115


bcause - 
every missing date key value is the average if its next and 
previous date key value... !

-------------------
another test case()
--------------------
Input:
---------
3
2019-01-10 10
2019-01-11 20
2019-01-13 10

Output:
---------
2019-01-10:10
2019-01-11:20
2019-01-12:15
2019-01-13:10

*/


const D = [
    { date: new Date('2019-01-01'), key: 100 },
    { date: new Date('2019-01-04'), key: 115 }
];

missingDays = [];
answer = [];

for (let i = 0; i < D.length - 1; i++) {
    const firstDate = new Date(D[i].date).getDate() ;
    const secondDate = new Date(D[i+1].date).getDate() ;
    daysDiff = secondDate - firstDate ;
    avgKey = (D[i+1].key - D[i].key) / daysDiff ;
    count = 1 ;
    while (count < daysDiff) {
        let obj = {
            date: new Date(new Date(D[i].date).setDate(D[i].date.getDate() + count)) ,
            key: D[i].key + count * avgKey
        }
        missingDays.push(obj) ;
        count++ ;   
    }
}

answer.push(...D, ...missingDays);
answer.sort((a, b) => a.date - b.date );
console.log(answer);

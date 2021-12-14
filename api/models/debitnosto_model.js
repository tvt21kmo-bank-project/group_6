const db = require('../database');
//luodaan bank-niminen objekti
//ja sen sisään tarvittavat funktiot
const bank = {

    debit: function(postData, callback){
        return db.query('call nostarahaa(?,?,?)',
        [postData.idKortti, postData.summa, postData.Tila1],
        callback);
    },
};
//exportilla viedään ulos bank objekti
module.exports = bank;
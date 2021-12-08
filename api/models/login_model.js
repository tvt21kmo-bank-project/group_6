const db = require('../database');

const login={
  checkPassword: function(username, callback) {
      return db.query('SELECT pin FROM pankkiautomaatti.kortti WHERE idKortti = ?',[username], callback); 
    },
    idKortti: function(idKortti, callback) {
      return db.query('select Tila from Kortti where idKortti=? AND tila =0', [idKortti], callback);
    },
};
          
module.exports = login;
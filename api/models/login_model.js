const db = require('../database');

const login={
  checkPassword: function(username, callback) {
      return db.query('SELECT pin FROM pankkiautomaatti.kortti WHERE idKortti = ?',[username], callback); 
    }
};
          
module.exports = login;
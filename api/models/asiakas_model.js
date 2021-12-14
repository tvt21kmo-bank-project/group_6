const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const user={

  getById: function(id, callback) {         
    return db.query('select Nimi from Asiakas JOIN kortti ON Asiakas.idAsiakas=Kortti.Asiakas_idAsiakas where idKortti=?', [id], callback);         // tasta tulee kortti idlla asiakkaan nimi
  },
  add: function(user, callback) {
    bcrypt.hash(user.pin, saltRounds, function(err, hash) {
      return db.query('insert into kortti (idKortti, pin, Asiakas_idAsiakas, Tili_idTili, Tila) values(?,?,?,?,?)',       // tassaa yritetty kaikkea kummallista
      [user.idKortti, hash, user.Asiakas_idAsiakas, user.Tili_idTili, user.Tila], callback); 
    });
  },
  lukitus: function(postData, callback) {         
    return db.query('UPDATE pankkiautomaatti.kortti SET Lukittu = 1 WHERE idKortti=?', [postData.id], callback);         // tasta tulee kortti idlla asiakkaan nimi
  },
  lukitusavaa: function(postData, callback) {         
    return db.query('UPDATE pankkiautomaatti.kortti SET Lukittu = 0 WHERE idKortti=?', [postData.id], callback);         // tasta tulee kortti idlla asiakkaan nimi
  },
}
          
module.exports = user;
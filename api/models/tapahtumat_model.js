const db = require('../database');

const tapahtumat = {
  getById: function(id, callback) {
    return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili where idKortti=? order by idTilitapahtumat desc', [id], callback);
},
  saldoTapahtuma: function(id, callback) {
  return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili where idKortti=? order by idTilitapahtumat desc limit 5', [id], callback);
  //select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili  where idKortti=5432 order by idTilitapahtumat desc limit 5;
  },

  TapahtumaLisaa: function(id, callback) {
    return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili where idKortti=? order by idTilitapahtumat desc limit 10 offset = ?', [id, offset], callback);
    //select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili  where idKortti=5432 order by idTilitapahtumat desc limit 5;
},

 /* getAll: function(callback) {
    return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat', callback);
  },*/
};
module.exports = tapahtumat; 
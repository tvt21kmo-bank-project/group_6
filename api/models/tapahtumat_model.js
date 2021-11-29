const db = require('../database');

const tapahtumat = {
  getById: function(id, callback) {
    return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili where idKortti=?', [id], callback);
},
  getAll: function(callback) {
    return db.query('select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat', callback);
  },
};
module.exports = tapahtumat;
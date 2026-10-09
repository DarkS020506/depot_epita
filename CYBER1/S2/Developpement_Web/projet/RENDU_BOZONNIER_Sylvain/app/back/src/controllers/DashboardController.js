// BOZONNIER Sylvain - CyberA 2028
const DashboardModel = require('../models/DashboardModel');

class DashboardController {
  getDashboard(query, body) {
    return DashboardModel.getStats();
  }
}

module.exports = new DashboardController();

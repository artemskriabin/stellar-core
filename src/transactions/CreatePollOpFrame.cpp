#include "util/asio.h"
#include "transactions/CreatePollOpFrame.h"
#include "OfferExchange.h"
#include "database/Database.h"
#include "ledger/LedgerTxn.h"
#include "ledger/LedgerTxnEntry.h"
#include "ledger/LedgerTxnHeader.h"
#include "transactions/TransactionUtils.h"
#include "util/Logging.h"
#include "util/XDROperators.h"
#include <algorithm>

#include "main/Application.h"

namespace stellar
{

using namespace std;

CreatePollOpFrame::CreatePollOpFrame(Operation const& op,
                                     OperationResult& res,
                                     TransactionFrame& parentTx)
    : OperationFrame(op, res, parentTx)
    , mCreatePoll(mOperation.body.createPollOp())
{
}

bool
CreatePollOpFrame::doApply(AbstractLedgerTxn& ltx)
{
    
}

bool
CreatePollOpFrame::doCheckValid(uint32_t ledgerVersion)
{
    if isValidJ

    return true;
}

void
CreatePollOpFrame::insertLedgerKeysToPrefetch(
    std::unordered_set<LedgerKey>& keys) const
{
    keys.emplace(accountKey(mCreatePoll.destination));
}
}
